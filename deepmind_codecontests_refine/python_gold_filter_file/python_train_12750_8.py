#in the name of god
#Mr_Rubik
#CodeForces,Problemset
sepData=[[],[],[2],[3],[2,2,3],[5],[5,3],[7],[7,2,2,2],[7,2,3,3]]
digit=input()
number=input()
ans=[]
for i in number:
    if i!='1' and i!='\r':
        for j in sepData[int(i)]:
            ans.append(j)
ans.sort(reverse=True)
for i in ans:
    print(i,end="")