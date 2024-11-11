import calendar
a=input()
b=[calendar.month_name[i] for i in range(13)][1:]
print(b[(int(input())+b.index(a))%12])