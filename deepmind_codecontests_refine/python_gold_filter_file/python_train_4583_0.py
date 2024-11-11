n,q = map(int,input().split())

tmp =  [input().split() for i in range(n)]
a = [[name,int(time)] for name,time in tmp]

total_time = 0

count = 0
while(a):
    current = a.pop(0)
    if(current[1] > q):
        current[1] -= q
        a.append(current)
        total_time += q
    else:
        total_time += current[1]
        print(current[0],total_time,sep = " ")
