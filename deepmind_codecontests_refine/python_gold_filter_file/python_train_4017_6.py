a=input()
b = input()
if len(a)==len(b):
    print([len(a),"-1"][a==b])
else:
    print(max(len(a),len(b)))