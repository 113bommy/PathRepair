n=int(input())
ans=[]
for i in range(1,n+1):
                place,light,begin,end=input().split()
                place=int(place)
                light=int(light)
                begin=int(begin)
                end=int(end)
                count=(begin-1)//light+(place)//light-end//light
                ans.append(count)
for elem in ans:
    print(elem)