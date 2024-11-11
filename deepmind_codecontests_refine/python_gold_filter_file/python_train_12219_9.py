n=int(input())
l=list(map(int,input().split()))
c=bi=ba=0
j=1
for i in range(1,n+1):
    if j==1:
        c+=l[i-1]
        j+=1
    elif j==2:
        bi+=l[i-1]
        j+=1
    else:
        j=1
        ba+=l[i-1]
#print(c,bi,ba)
if c>bi and c>ba:
    print('chest')
elif bi>c and bi>ba:
    print('biceps')
elif ba>bi and ba>c:
    print('back')
else:
    print('unambiguous')
