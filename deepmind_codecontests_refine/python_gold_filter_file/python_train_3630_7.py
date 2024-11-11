from datetime import date
week=["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
while True:
    a,b=map(int,input().split())
    if a==0:
        break
    print(week[date(2004,a,b).weekday()])