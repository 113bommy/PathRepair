n=int(input())
x=[int(x) for x in input().split()]
if n>=3:
    chest=sum(x[0::3])
    bicep=sum(x[1::3])
    back=sum(x[2::3])
    if chest>bicep and chest>back:ans="chest"
    elif bicep>chest and bicep>back:ans="biceps"
    else:ans="back"
elif n==1:
    ans="chest"
else:
    if x[0]>x[1]:ans="chest"
    else:ans="biceps"
print(ans)