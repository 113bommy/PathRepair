n = int(input())
r = lambda : list(map(int, input().split()))
arr = r()

arr.sort()
# print(arr)
x = arr[:(n+1)//2]
y = arr[(n+1)//2:]

for i,j in zip(x,y):
    print(i,j,end = " ")

if n%2: print(x[-1])
