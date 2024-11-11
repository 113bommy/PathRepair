n=int(input())
a=list(map(int, input().split()))
arr=[abs(a[i]-a[i+1])*(-1)**i for i in range(n-1)]
maximum=0
summ=0
for j in arr:
    if j>0 or abs(j)<abs(summ):
        summ+=j
    else:
        summ=0
    maximum=max(maximum, abs(summ))
summ=0
for k in arr[1:]:
    if k<0 or abs(k)<abs(summ):
        summ+=k
    else:
        summ=0
    maximum=max(maximum, abs(summ))
print(maximum)
    
