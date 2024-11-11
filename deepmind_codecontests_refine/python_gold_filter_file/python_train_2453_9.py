day={}
day['sunday']=0
day['monday']=1
day['tuesday']=2
day['wednesday']=3
day['thursday']=4
day['friday']=5
day['saturday']=6

day1=input()
day2=input()
diff=(day[day2]-day[day1])%7
if diff==0 or diff==3 or diff==2:
    print('YES')
else:
    print('NO')