output = 0
l = []
calories = input().split(" ")
for i in range(len(calories)):
    calories[i] = int(calories[i])
    l.append(0)
inputs = input()
for i in range(len(inputs)):
    l[int(inputs[i])-1]+=1
for i in range(len(l)):
    output+=l[i]*calories[i]
print(output)
