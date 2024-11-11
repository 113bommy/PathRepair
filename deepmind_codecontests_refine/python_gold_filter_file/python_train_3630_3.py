import datetime

date_list = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

while True:
    m, d = map(int, input().split())
    if m == 0 and d == 0:
        break
    print(date_list[datetime.date(2004, m, d).weekday()])

