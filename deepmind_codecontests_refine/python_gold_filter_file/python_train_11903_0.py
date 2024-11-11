import array 
k = int(input())
string = tuple(input())
ones = string.count("1")
count = 0
modified_string = array.array("i", range(ones+1))
for i in range(ones+1):
    modified_string[i] = -1
i = 0
n = len(string)
pos = 0
while i < n:
    if string[i] == "0":
        count += 1
    else:
        modified_string[pos] = count
        pos += 1
        count = 0
    if i == n - 1:
        modified_string[pos] = count
        pos += 1
    i += 1
i = 0
ans = 0
n = len(modified_string)
if k == 0:
    for each in modified_string:
        if each != 0:
            ans += (each*(each + 1))//2
else:
    while i + k < n:
        ans += (modified_string[i] + 1) * (modified_string[i + k] + 1)
        i += 1
print(ans)