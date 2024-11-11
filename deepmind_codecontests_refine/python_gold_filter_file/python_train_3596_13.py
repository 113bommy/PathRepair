a,b=input().strip().split(" ")
a,b=[int(a),int(b)]
ans=b
count=0
for i in range(a):
    l=list(input().strip().split(" "))
    if l[0]=="+":
        ans=ans+int(l[1])
    if l[0]=="-":
        ans=ans-int(l[1])
        if ans>=0:
            pass
        else:
            ans=ans+int(l[1])
            count=count+1
print(str(ans)+" "+str(count))
    




                          
