import sys

a = sys.stdin.read()
alphabet = "abcdefghijklmnopqrstuvwxyz"

for i in alphabet:
    print(i + " : " + str(a.lower().count(i)) )