x = int(input())
array = list(map(int , input().split()))
array.sort()
print(array[(x-1)//2])