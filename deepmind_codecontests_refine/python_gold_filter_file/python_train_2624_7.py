def sec(total,needed):
    if total>=needed:
        return needed
    k=needed//total
    #print(k)
    needed=needed-(k*total)
    ans=(needed*((k+1)**2))+((total-needed)*k**2)
    return ans
    

n= int(input())
ans=[]
for i in range(n):
    total,needed=[int(i) for i in input().split()]
    ans.append(sec(total,needed))
    

for i in ans:
    print(i)