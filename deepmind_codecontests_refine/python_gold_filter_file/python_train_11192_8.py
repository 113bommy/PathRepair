def almost_binary_search(array, x):
    left = 0
    right = len(array) - 1
    index = 0
    while left <= right:
        mid = (left+right)//2
        if array[mid] <= x:
            index = mid + 1
            left = mid + 1
        elif array[mid] > x:
            right = mid-1
       
    return index

n, m = [int(i) for i in input().split()]
ls1 = [int(i) for i in input().split()]
ls2 = [int(i) for i in input().split()]

ls1.sort()

for i in range(len(ls2)):
  j = almost_binary_search(ls1, ls2[i])
  if(i != len(ls2)-1):
    print(j, end=' ')
  else:
    print(j, end='')