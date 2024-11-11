m=input()
k=int(input())
month=["January", "February", "March", "April", "May", "June", 
"July", "August", "September", "October", "November", "December"]
ind=month.index(m)
print(month[(ind+k)%12])