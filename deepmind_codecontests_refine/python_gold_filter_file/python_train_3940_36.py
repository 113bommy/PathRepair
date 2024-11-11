n=int(input())
k=int(input())
a=1
for _ in[0]*n:a+=min(a,k)
print(a)