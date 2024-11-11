n , k = map(int , input().split())
l = list(map(int , input().split()))
ans = []
for i in range(k):
    minn ,maxn = min(l) , max(l)
    minindex , maxindex = l.index(minn) , l.index(maxn)
    if minn != maxn :
        ans.append((maxindex+1,minindex+1))
        l[minindex] += 1
        l[maxindex] -=1
        #print(l)
        
print(max(l)-min(l) , len(ans))
for i in ans :
    print(*i)