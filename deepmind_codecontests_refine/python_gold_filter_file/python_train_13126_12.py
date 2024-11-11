n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if sum(a[0:len(a)]) >= sum(b[0:len(b)]):
    print("Yes")
else:
    print("No")
