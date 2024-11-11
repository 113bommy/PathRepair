j = int(input())
n = list(map(int,input().split()))
n.sort()
if j % 2 == 0:
    print(n[len(n)//2 - 1])
else:
    print(n[len(n)//2])