import sys
pw = sys.stdin.readline().strip()
if len(pw) >= 5 \
        and any(c.isupper() for c in pw) \
        and any(c.islower() for c in pw) \
        and any(c.isdigit() for c in pw):
    print("Correct")
else:
    print("Too weak")
