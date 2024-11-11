W,a,b=map(int,input().split(' '))
print(max(0,b-(a+W))) if a<=b else print(max(0,a-(b+W)))
