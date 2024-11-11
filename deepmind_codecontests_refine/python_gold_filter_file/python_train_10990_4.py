import math
def solve(m,d):
    months = [31,28,31,30,31,30,31,31,30,31,30,31]
    rem = 0
    count = 4
    if months[m-1] == 31:
      rem = 4
      count = 5
    elif months[m-1] == 30:
      rem = 5
      count = 5
    
    if d-1 > rem :
      count += 1

    return count
    
  
def main():
  i =list(map(int,input().split(' ')))
  print(solve(*i))

main()