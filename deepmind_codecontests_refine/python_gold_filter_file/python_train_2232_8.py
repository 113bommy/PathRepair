a=[int(k) for k in input().split()]
s=input()
val=0
for i in s:
    k=int(i)
    val+=a[k-1]
print(val)