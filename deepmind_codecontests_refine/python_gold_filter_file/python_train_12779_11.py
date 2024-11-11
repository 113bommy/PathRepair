import sys
input=sys.stdin.readline
l=input().split()
a=int(l[0])
b=int(l[1])
c=int(l[2])
d=int(l[3])
l=[[0 for i in range(50)]for i in range(50)]
print(50,50)
for i in range(12):
    for j in range(50):
        l[i][j]='A'
for i in range(12,25):
    for j in range(50):
        l[i][j]='B'
for i in range(25,37):
    for j in range(50):
        l[i][j]='C'
for i in range(37,50):
    for j in range(50):
        l[i][j]='D'
a-=1
b-=1
c-=1
d-=1
rem=d
for i in range(1,11):
    for j in range(1,49):
        if(rem):
            if(i%3==j%3):
                l[i][j]='D'
                rem-=1
rem=c
for i in range(13,24):
    for j in range(1,49):
        if(rem):
            if(i%3==j%3):
                l[i][j]='C'
                rem-=1
rem=b
for i in range(26,36):
    for j in range(1,49):
        if(rem):
            if(i%3==j%3):
                l[i][j]='B'
                rem-=1
rem=a
for i in range(38,49):
    for j in range(1,49):
        if(rem):
            if(i%3==j%3):
                l[i][j]='A'
                rem-=1
for i in range(50):
    for j in range(50):
        print(l[i][j],end="")
    print()