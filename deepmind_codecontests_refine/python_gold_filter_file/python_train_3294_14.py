t=int(input())


for e in range(t):
    n,k=map(int,input().split())
    taps=list(map(int,input().split()))
    
    time=taps[0]
    
    for i in range(k-1):
        time=max(time,1+(taps[i+1]-taps[i])//2)
    time=max(time,n-taps[-1]+1)
    print(time)