n = int(input())
inputs = []
for i in range(n):
    inputs.append(int(input()))
c = 0 
for i in range(len(inputs)):
    if inputs[i]%2 == 0:
        inputs[i] = int(inputs[i]/2)
    else:
        if inputs[i] <= 0:
            inputs[i] = int(inputs[i]/2)-c%2
        else:
            inputs[i] = int(inputs[i]/2)+(c+1)%2
        c += 1
        
for i in range(len(inputs)):
    print(inputs[i])