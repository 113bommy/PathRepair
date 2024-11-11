a,b = map(int, input().split())

s1 = input().split()
s2 = input().split()

numyears = int(input())

years = []
for i in range(numyears):
    years.append(int(input()))

for year in years:
    
    c1 = ""
    c2 = ""
    output = ""
    if year <= (a):
        c1 = s1[year-1]
    elif year > (a):
        c1 = s1[(year % a) - 1]
    if year <= (b):
        c2 = s2[year-1]
    elif year > (b):
        c2 = s2[(year % b) - 1]
    output = c1+c2
    print(output)