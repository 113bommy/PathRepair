from pprint import pprint

__BASE     = 1000000007
__MOD      = (2**64)
__INV      = 13499267949257065399

def main():
    s,t = input(),input()
    x = len(t)
    mp = {}
    hashv = 0
    for i in range(len(s)):
        if i - x >= 0:
            hashv = hashv - ord(s[i-x]) * ( __BASE ** (x-1) )
        hashv *= __BASE
        hashv %= __MOD
        hashv += ord(s[i])
        hashv %= __MOD
        if i >= x-1:
            if hashv in mp:
                mp[hashv].append(i)
            else:
                mp[hashv] = [i]
    hashv = 0
    for c in t:
        hashv *= __BASE
        hashv %= __MOD
        hashv += ord(c)
    if hashv in mp:
        for pos in mp[hashv]:
            print(pos-(x-1))

if __name__ == "__main__":
    main()