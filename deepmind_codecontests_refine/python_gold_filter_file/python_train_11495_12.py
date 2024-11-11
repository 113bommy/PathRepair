n=int(input())
l=list(map(int,input().split()))
f=0
c=0
fi=0
for i in range(n):
    if l[i]==25:
        c+=1
    elif l[i]==50 and c>=1:
        c-=1
        fi=fi+1
    elif l[i]==100 and fi>=1 and c>=1:
        c-=1
        fi=fi-1
    elif l[i]==100 and c>=3:
        c-=3
    else:
        f=1
        break
print("YES") if f==0 else print("NO")
