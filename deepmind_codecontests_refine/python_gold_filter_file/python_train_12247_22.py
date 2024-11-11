n , d = map(int,input().split())
arr = list(input())
start,end,count =0,n-1,0
while(start < end):
    check = count
    for i in range(d,0,-1):
        if(start+i < n):
            if(arr[start+i] == '1'):
                count+=1
                start = start+i
                break
    if(count==check):
        print(-1)
        break
if(count!=check):
    print(count)