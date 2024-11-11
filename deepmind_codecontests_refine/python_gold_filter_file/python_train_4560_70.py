N,K=map(int,input().split())
A=sorted(map(int,input().split()))
F=sorted(map(int,input().split()))[::-1]

left,right=-1,10**12
while left + 1 < right:
    mid = (left + right)//2
    if sum([max(0,a-mid//f) for a,f in zip(A,F)])>K:
        left = mid
    else:
        right = mid
print(right)