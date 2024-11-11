n = int(input())

people = [int(x) for x in input().split()]

people.sort()

ans = 9999999999
for i in range(n*2):
    for j in range(n*2-1):
        if i != j:
            counter = 0
            temp_people = people.copy()
            
            temp_people.pop(i)
            temp_people.pop(j)
            
            for k in reversed(range(0,n-1)):
                counter += temp_people[len(temp_people)-1] - temp_people[len(temp_people)-2]
                temp_people.pop(len(temp_people)-1)
                temp_people.pop(len(temp_people)-1)
                
            ans = min(counter,ans)

print(ans)