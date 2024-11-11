inputs = list(map(int, input().rstrip().split()))

size = int(inputs[0]*inputs[1])
numberoftiles = 0

if size >= 2 : 
    numberoftiles = int(size / 2)

print(numberoftiles)
