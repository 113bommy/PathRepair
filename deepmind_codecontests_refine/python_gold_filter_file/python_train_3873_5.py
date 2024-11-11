for _ in range(int(input())):
    n=int(input())
    s1=input()
    s2=input()
    s1=[i for i in s1]
    s2=[i for i in s2]
    freq={}
    for i in s1:
        if i not in freq:
            freq[i]=0
        freq[i]+=1 
    for i in s2:
        if i not in freq:
            freq[i]=0
        freq[i]+=1
    f=True
    for i in freq:
        if freq[i]%2!=0:
            f=False
            print('No')
            break
    if not f:
        continue
    pos=0
    ans=[]
    f=True
    while pos<len(s1):
        if s1[pos]==s2[pos]:
            pos+=1
            continue
        idx=-1
        for i in range(pos+1,len(s1)):
            if s1[pos]==s1[i]:
                idx=i 
                break
        if idx!=-1:
            s2[pos],s1[idx]=s1[idx],s2[pos]
            ans.append((idx+1,pos+1))
            pos+=1 
            continue
        s1[pos],s2[pos]=s2[pos],s1[pos]
        ans.append((pos+1,pos+1))
        idx=-1
        for i in range(pos+1,len(s1)):
            if s1[pos]==s1[i]:
                idx=i 
                break
        if idx!=-1:
            s2[pos],s1[idx]=s1[idx],s2[pos]
            ans.append((idx+1,pos+1))
            pos+=1
            continue
        s1[pos],s2[pos]=s2[pos],s1[pos]
        ans.pop()
        idx=-1
        for i in range(pos+1,len(s2)):
            if s2[i]==s2[pos]:
                idx=i
                break
        if idx==-1:
            f=False
            break
        s1[pos],s2[idx]=s2[idx],s1[pos]
        ans.append([pos+1,idx+1])
    if f:
        # print(s1,s2)
        print('Yes')
        print(len(ans))
        for i in ans:
            print(i[0],i[1])
    else:
        print('No')
        
                