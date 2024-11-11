n,c = map(int,input().split())
point = [*map(int,input().split())]
time=  [*map(int,input().split())]
count1,count2 = 0,0
limak,rade =0,0
for i in range(n):
    count1 += time[i]
    limak += max(point[i]-c*count1,0)
    count2 += time[n-i-1]
    rade += max(point[n-i-1]-c*count2,0)

if limak>rade:
    print('Limak')
elif rade>limak:
    print('Radewoosh')
else:
    print('Tie')


