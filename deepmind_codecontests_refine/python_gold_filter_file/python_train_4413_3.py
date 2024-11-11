a=int(input())
b=list(map(int, input().split()))
c, d=sorted(map(int, input().split()))
x=sum(b[c-1:d-1])
cnt=0
print(min(x, sum(b)-x))