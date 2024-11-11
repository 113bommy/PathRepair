N = int(input())
arr = list(map(int, input().split()))
r=0
for i in sorted(arr):
    if r>i:N-= 1
    else:r=max(r+1,i-1)
print(N)
