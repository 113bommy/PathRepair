a = input()
b = input()
i = 0
count = 0
while i <= len(a)-len(b):
    if a[i:i+len(b)] == b:
        i+=len(b)
        count+=1
    else:
        i+=1
        #print(a, n)
print(count)