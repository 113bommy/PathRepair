
n = int(input())

arr = []

for i in range(n):
    s = input()
    arr.append(s)

dic = {}
for i in range(len(arr[0])):
    if arr[0][i] not in dic:
        dic[arr[0][i]]=1
    else:
        dic[arr[0][i]]+=1

fl = 0

for i in range(1,n):
    mp = {}
    for j in range(len(arr[i])):
        if arr[i][j] not in mp:
            mp[arr[i][j]]=1
        else:
            mp[arr[i][j]]+=1
    for x in mp:
        if x in dic:
            if dic[x]==mp[x]:
                pass
            else:
                fl = 1
                break
        else:
            fl=1
            break
    if fl==1:
        break

if fl==1:
    print(-1)
else:
    ans = 1000000000000000000

    for i in range(n):
        an = 0

        for j in range(n):
            k = 0
            s = arr[j]
            while(k<len(arr[i])):
                if s==arr[i]:
                    break
                s = s[1:len(s)]+s[0]
                an+=1
                k+=1
                #print(s,arr[i])
            if s==arr[i]:
                pass
            else:
                an=1000000000000000000000000000
        #print(an)
        ans = min(an,ans)
    if ans>=1000000000000000000:
        print(-1)
    else:
        print(ans)

        


    




