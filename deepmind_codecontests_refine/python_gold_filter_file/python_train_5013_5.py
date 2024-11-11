n=int(input())
for _ in range(n):
    s=input()
    ans=[]
    thing={}
    for i in s:
        ans.append(i)
    ans.sort()
    chars=[]
    for i in ans:
        if i in thing:
            thing[i]+=1
        else:
            thing[i]=1
            chars.append(i)
    if len(thing)==2 and ord(ans[0])==ord(ans[-1])-1:
        print('No answer')
        continue
    if len(thing)==3 and ord(ans[0])==ord(ans[-1])-2:
        print('No answer')
        continue
    ans2=[]
    if len(thing)==3 and ord(chars[0])==ord(chars[1])-1:
        for i in range(thing[chars[0]]):
            ans2.append(chars[0])
        for i in range(thing[chars[2]]):
            ans2.append(chars[2])
        for i in range(thing[chars[1]]):
            ans2.append(chars[1])
    elif len(thing)==3 and ord(chars[1])==ord(chars[2])-1:
        for i in range(thing[chars[1]]):
            ans2.append(chars[1])
        for i in range(thing[chars[0]]):
            ans2.append(chars[0])
        for i in range(thing[chars[2]]):
            ans2.append(chars[2])
    elif len(thing)==4:
        for i in range(thing[chars[2]]):
            ans2.append(chars[2])
        for i in range(thing[chars[0]]):
            ans2.append(chars[0])
        for i in range(thing[chars[3]]):
            ans2.append(chars[3])
        for i in range(thing[chars[1]]):
            ans2.append(chars[1])
    else:
        for i in range(0,len(thing),2):
            for j in range(thing[chars[i]]):
                ans2.append(chars[i])
        for i in range(0,len(thing)-1,2):
            for j in range(thing[chars[i+1]]):
                ans2.append(chars[i+1])
    print(''.join(ans2))