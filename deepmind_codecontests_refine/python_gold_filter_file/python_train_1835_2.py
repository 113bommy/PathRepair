n = int(input())
a = input()
MAX = 0
end = 0
for i in range(n):
    start = end
    end = start+1
    while a[start:end].islower():
        if MAX < len(set(a[start:end])):
            MAX = len(set(a[start:end]))
        end+=1
        if end > n:
            break
print(MAX)