datain = []
for i in range(3):
    datain.append(input())

n,m = map(int, datain[0].split(' '))

boys_data = list(map(int, datain[1].split(' ')))
girls_data = list(map(int, datain[2].split(' ')))

happy_boys = [0]*n
happy_girls = [0]*m

for i in range(1, len(boys_data)):
    happy_boys[boys_data[i]] = 1

for i in range(1, len(girls_data)):
    happy_girls[girls_data[i]] = 1

    
days = (n*m*2)

for i in range(days):
    boy = i % n
    girl = i % m

    if (happy_boys[boy] == 1) or (happy_girls[girl] == 1):
        happy_boys[boy]   = 1 
        happy_girls[girl] = 1

if (sum(happy_boys) == n) and (sum(happy_girls) == m):
    print("Yes")

else:
    print("No")

    
    
