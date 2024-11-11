t = int(input())
s = input()
white = []
white_count = 0
temp = list(s)
for j in range(len(s)-1):
    if(temp[j]=='B'):
        white_count+=1
        temp[j+1]='W' if temp[j+1]=='B' else 'B'
        white.append(j+1)
if(temp[-1]=='W'):
    print(white_count)
    if(len(white)!=0):
        print(*white)
else:
    black = []
    black_count = 0
    temp = list(s)
    for j in range(len(s)-1):
        if(temp[j]=='W'):
            black_count+=1
            temp[j+1]='B' if temp[j+1]=='W' else 'W'
            black.append(j+1)
    if(temp[-1]=='B'):
        print(black_count)
        if(len(black)!=0):
            print(*black)
    else:
        print(-1)
    
        