try:
    text = ""
    while True:
        text += input()
except:
    for s in [chr(k) for k in range(97,97+26)]:
        print(s,":",text.lower().count(s))