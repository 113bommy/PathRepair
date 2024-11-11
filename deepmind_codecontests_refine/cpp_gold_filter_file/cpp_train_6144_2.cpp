#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>

#define Lens 250
#define Nil -1
using namespace std;

struct Node
{
	int p, l, r;
};

int N,sum;
Node Tr[Lens];

void maketree()
{
	int m, l, r;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> l >> r;
		Tr[m].l = l;
		Tr[l].p = m;
		Tr[m].r = r;
		Tr[r].p = m;
	}
}

void Preorder(int i)
{
	if (i == Nil)
		return;
	cout << ' '<< i;
	Preorder(Tr[i].l);
	Preorder(Tr[i].r);
}

void Inorder(int i)
{
	if (i == Nil)
		return;
	Inorder(Tr[i].l);
	cout << ' ' << i;
	Inorder(Tr[i].r);
}

void Postorder(int i)
{
	if (i == Nil)
		return;
	Postorder(Tr[i].l);
	Postorder(Tr[i].r);
	cout << ' ' << i;
}

int main()
{
	int root;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Tr[i].p = Tr[i].l = Tr[i].r = Nil;
	}
	maketree();
	for (int i = 0; i < N; i++)
	{
		if (Tr[i].p == Nil)
			root = i;
	}
	cout << "Preorder" << endl;
	Preorder(root);
	cout << endl;
	cout << "Inorder" << endl;
	Inorder(root);
	cout << endl;
	cout << "Postorder" << endl;
	Postorder(root);
	cout << endl;


	return 0;
}
