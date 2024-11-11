s = str(input())
s = list(s)
s1 = s[::-1]
answer = ""
output = s
if len(s) == 1:
    s += s
    output = list(s)
elif s == s1:
    for element in s:
        s.insert(int(len(s)/2), element)
        if s == s[::-1]:
            break
        else:
            s.pop(int(len(s) / 2) - 1)
    output = s
else:
    for letter in s:
        count = 0
        while count <= len(s):
            s.insert(count, letter)
            s1 = s[::-1]
            if s1 == s:
                output = s1
            s.pop(count)
            count += 1

if output == output[::-1]:
    for letter in output:
        answer += letter
    print (answer)
else:
    print ("NA")
