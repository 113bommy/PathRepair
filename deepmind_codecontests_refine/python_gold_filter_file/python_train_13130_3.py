n=int(input())
for i in range(n):
    li=[]
    origli=[]
    q=int(input())
    for j in range(q):
        a,b=input().split(" ")
        a,b=int(a),int(b)
        li.append([a,b])
        origli.append([a,b])
    li.sort()
    newli=[li[0]]
    i=1
    s1=set()
    s2=set()
    s1.add(tuple(li[0]))
    while(i<len(li)):
        if li[i][0]<=newli[-1][1]:
            if tuple(li[i-1]) in s1:
                s1.add(tuple(li[i]))
            else:
                s2.add(tuple(li[i]))
            if newli[-1][1]<li[i][1]:
                newli[-1][1]=li[i][1]
            i+=1
        else:
            if tuple(li[i-1]) in s1:
                s2.add(tuple(li[i]))
            else:
                s1.add(tuple(li[i]))
            newli.append([li[i][0],li[i][1]])
            i+=1
    #print(newli)
    ans=[]
    if(len(newli)==1):
        print(-1)
        continue
    for i in range(len(origli)):
        if tuple(origli[i]) in s1:
            ans.append(1)
        elif tuple(origli[i]) in s2:
            ans.append(2)

    joined_string = ' '.join([str(v) for v in ans])
    print(joined_string)