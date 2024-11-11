'''Author- Akshit Monga'''
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    dict={}
    for i in range(n):
        s=input()
        dict[s]=1
    ans=[0 for x in range(m)]
    arr=list(dict.keys())
    n=len(arr)
    if len(arr)==1:
        print(arr[0])
        continue
    if len(arr)==2:
        s1 = arr[0]
        s2 = arr[1]
        save = []
        for i in range(m):
            if s1[i] != s2[i]:
                save.append(i)
            if len(save) > 2:
                ans = -1
                break
            if s1[i] == s2[i]:
                ans[i] = s1[i]
        if ans == -1:
            print(ans)
            continue
        if len(save) == 2:
            index1 = save[0]
            index2=save[1]
            ans[index1]=s1[index1]
            ans[index2]=s2[index2]
            for i in range(m):
                print(ans[i], end="")
            print()
            continue
        else:
            print(s1)
            continue
    s1=arr[0]
    s2=arr[1]
    save=[]
    for i in range(m):
        if s1[i]!=s2[i]:
            save.append(i)
        if len(save)>2:
            ans=-1
            break
        if s1[i]==s2[i]:
            ans[i]=s1[i]
    if ans==-1:
        print(ans)
        continue
    if len(save)==2:
        index1=save[0]
        index2=save[1]
        # print(index1,index2)
        # print(ans)
        # print(s1,s2)
        ans1=[0 for x in range(m)]
        ans2=[0 for x in range(m)]
        for i in range(m):
            if i==index1:
                ans1[i]=s1[i]
                ans2[i]=s2[i]
            elif i==index2:
                ans1[i] = s2[i]
                ans2[i] = s1[i]
            else:
                ans1[i]=ans2[i]=ans[i]
        s3=arr[2]
        p=q=0
        for i in range(m):
            if i not in save:
                if s3[i]!=ans[i]:
                    p+=1
                    q+=1
            else:
                if s3[i]!=ans1[i]:
                    p+=1
                if s3[i]!=ans2[i]:
                    q+=1
        # print(ans1,ans2)
        # print(p,q)
        if p>=2 and q>=2:
            ans=-1
        elif p<2:
            ans=ans1
        elif q<2:
            ans=ans2
        if ans==-1:
            print(ans)
            continue

        assert len(arr)==n
        for i in range(n-3):
            var = 0
            st=arr[i+3]
            for j in range(m):
                if st[j]!=ans[j]:
                    var+=1
            if var > 1:
                # print(var)
                # print(st)
                ans = -1
                break
        if ans==-1:
            print(ans)
            continue
        for i in range(m):
            print(ans[i],end="")
        print()
    else:
        bool=0
        index1 = save[0]
        for i in range(n-2):
            st=arr[i+2]
            if bool==0:
                var=0
                for j in range(m):
                    if j!=index1:
                        if st[j]!=ans[j]:
                            var+=1
                if var>1:
                    ans=-1
                    break
                elif var==1:
                    bool=1
                    ans[index1]=st[index1]
            else:
                var=0
                for j in range(m):
                    if st[j] != ans[j]:
                        var += 1
                if var>1:
                    ans=-1
                    break
        if ans==-1:
            print(ans)
        else:
            if bool==0:
                ans[index1]='a'
            for i in range(m):
                print(ans[i],end="")
            print()