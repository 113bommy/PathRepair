m = input()
k=int(input())
month = ["January","February","March","April","May","June","July","August","September","October","November","December"]
b=month.index(m)
print(month[(b+k)%12])