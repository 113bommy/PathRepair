n=int(input())
t=list(map(int,input().split()))
t.sort()
print(sum(t[::2]))