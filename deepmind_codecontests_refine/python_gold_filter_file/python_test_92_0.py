test_case = int(input())

def make_equal(keep):
    while keep.count('ab') != keep.count('ba'):
        if keep.count('ab') > keep.count('ba'):
            keep = keep.replace('a','b',1)
        else :
            keep = keep.replace('b','a',1)
    return  keep

while test_case :
    string = input()
    if string.count('ab') == string.count('ba'):
        print(f"{string}")
    else :
        print(make_equal(string))
    test_case -= 1