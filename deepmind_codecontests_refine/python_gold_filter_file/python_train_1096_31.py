n = int(input())
a = list(map(int, input().split()))

def main():
  min_pos = a.index(1)
  max_pos = a.index(n)
  if len(a) % 2 == 0:
     mid = len(a)//2 - 0.5
  else:
    mid = len(a)//2
  
  # find out which one is closer to the midpoint 
  if abs(min_pos - mid) < abs(max_pos - mid):
    # if the min element is closer to the midpoint,
    
    if min_pos > mid:
      # if the min element is on the right half of the array
      if max_pos > mid:
        # if the max element is also on the right half,
        # swap the min element with the first element
        print(max_pos)
      
      else:
        # the min and max are on opposite sides.
        # swap the min element with the last element
        print(n - max_pos - 1)
        
      
    else:
      # if the min element is on the left half 
      # or at the middle of the array
      if max_pos < mid:
        # if the max element is also on the left half,
        # swap the min element with the last element
        print(n - max_pos - 1)
      
      else:
        # the min and max are on opposite sides.
        # swap the min element with the first element
        print(max_pos)
  
  else:
    # if the max element is closer to the midpoint
    
    if max_pos > mid:
      # if the max element is on the right half of the array
      if min_pos > mid:
        # if the min element is also on the right half,
        # swap the max element with the first element
        print(min_pos)
      
      else:
        # the min and max are on opposite sides.
        # swap the max element with the last element
        print(n - min_pos - 1)
        
      
    else:
      # if the max element is on the left half or
      # at the middle of the array
      if min_pos < mid:
        # if the min element is also on the left half,
        # swap the max element with the last element
        print(n - min_pos - 1)
      
      else:
        # the min and max are on opposite sides.
        # swap the max element with the first element
        print(min_pos)
  
  return
  
if __name__ == '__main__':
  main()
    
    


  