def count_vowels(s):
    d = set(['a', 'i', 'e', 'o', 'u', 'y'])
    count = 0
    for i in s:
        if i in d:
            count +=1
    return count


n = int(input().strip())
arr = [int(x) for x in input().strip().split(' ')]
possible = True
for x in range(n):
    if count_vowels(input().strip()) != arr[x]:
        possible = False
        break
print("YES" if possible else "NO")
