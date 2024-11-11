from math import ceil
r,g,b =map(int,input().split())
mins = 30 
Max = max(ceil(r/2),ceil(g/2),ceil(b/2))
total = Max * 3
mins += total

if ceil(b/2) == Max :
    mins-=1
elif ceil(g/2) == Max:
    mins-=2
elif ceil(r/2) == Max:
    mins-=3
print(mins)

