
def solve():
    jumps=0
    max_i=-1
    interval=0
    for i in range(1,len(ll)):
        interval+=1
        if(ll[i]=='1' and interval <=d):
            max_i=i
        
        if(interval==d):
            # print(max_i,' ',jumps)
            if(max_i==-1):
                return -1
            jumps+=1
            interval=i-max_i
            max_i=-1
    
    if(ll[len(ll)-1]=='1' and interval==0):
        # print('return jumps orig: ',jumps)
        return jumps
    else:
         return jumps +1


arr=[int(x) for x in input().split()]
n=arr[0]
d=arr[1]
ll=[ x for x in input()]

# print(ll)

print(solve())
