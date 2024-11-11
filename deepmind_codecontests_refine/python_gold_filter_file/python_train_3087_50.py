# Word Correcttion
def correction(s):
    vowels = ['a', 'e', 'i', 'o', 'u', 'y']
    vowels = set(vowels)
    ans = ""
    for i in s:
        if i in vowels:
            if not ans:
                ans += i
            elif ans[-1] not in vowels:
                ans += i
        else:
            ans += i
    return ans


n = int(input())
s = input()
print(correction(s))
