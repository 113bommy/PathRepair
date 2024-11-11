d={}
count=0
for i in range(int(input())):
    team_name=input()
    if team_name  not in d:
        d[team_name]=1
        count+=1
    else:
        d[team_name]+=1

l=list(d.keys())
if count==2:
    print(l[0] if d[l[0]]>d[l[1]] else l[1])
else:
    print(l[0])